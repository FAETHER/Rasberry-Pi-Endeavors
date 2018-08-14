
#include "GPIOClass.h"

using namespace std;

GPIOClass::GPIOClass():valuefd(-1),directionfd(-1),exportfd(-1),unexportfd(-1),gpionum("4")
{
        //GPIO4 is default
	this->export_gpio();
}

GPIOClass::GPIOClass(string gnum):valuefd(-1),directionfd(-1),exportfd(-1),unexportfd(-1),gpionum(gnum)
{
	//Instatiate GPIOClass object for GPIO pin number "gnum"
	this->export_gpio();
}

GPIOClass::~GPIOClass()
{
	this->unexport_gpio();
}


int GPIOClass::export_gpio()
{
	int statusVal = -1;
	string exportStr = "/sys/class/gpio/export";
	this->exportfd = statusVal = open(exportStr.c_str(),  O_WRONLY|O_SYNC);
	if (statusVal < 0){
		perror("could not open SYSFS GPIO export device");
        exit(1);
	}
	
	stringstream ss;
	ss << this->gpionum;
	string numStr = ss.str();
	statusVal = write(this->exportfd, numStr.c_str(), numStr.length());
	if (statusVal < 0){
		perror("could not write to SYSFS GPIO export device");
        exit(1);
	}
	
	statusVal = close(this->exportfd);
	if (statusVal < 0){
		perror("could not close SYSFS GPIO export device");
        exit(1);
	}

    return statusVal;
}

int GPIOClass::unexport_gpio()
{
	int statusVal = -1;
	string unexportStr = "/sys/class/gpio/unexport";
	this->unexportfd = statusVal = open(unexportStr.c_str(),  O_WRONLY|O_SYNC);
	if (statusVal < 0){
		perror("could not open SYSFS GPIO unexport device");
        exit(1);
	}

	stringstream ss;
	ss << this->gpionum;
	string numStr = ss.str();
	statusVal = write(this->unexportfd, numStr.c_str(), numStr.length());
	if (statusVal < 0){
		perror("could not write to SYSFS GPIO unexport device");
		cout<<numStr<<endl;
        exit(1);
	}
	
	statusVal = close(this->unexportfd);
	if (statusVal < 0){
		perror("could not close SYSFS GPIO unexport device");
        exit(1);
	}
	
	return statusVal;
}

int GPIOClass::setdir_gpio(string dir)
{
	int statusVal = -1;
	string setdirStr ="/sys/class/gpio/gpio" + this->gpionum + "/direction";
	
	
	this->directionfd = statusVal = open(setdirStr.c_str(), O_WRONLY|O_SYNC); // open direction file for gpio
		if (statusVal < 0){
			perror("could not open SYSFS GPIO direction device");
        exit(1);
		}
		
	if (dir.compare("in") != 0 && dir.compare("out") != 0 ) {
		fprintf(stderr, "Invalid direction value. Should be \"in\" or \"out\". \n");
		exit(1);
	}
		
	statusVal = write(this->directionfd, dir.c_str(), dir.length());
	if (statusVal < 0){
		perror("could not write to SYSFS GPIO direction device");
        exit(1);
	}
	
	statusVal = close(this->directionfd);
	if (statusVal < 0){
		perror("could not close SYSFS GPIO direction device");
        exit(1);
	}

	    return statusVal;
}


int GPIOClass::setval_gpio(string val)
{

    int statusVal = -1;
	string setValStr = "/sys/class/gpio/gpio" + this->gpionum + "/value";
	
	this->valuefd = statusVal = open(setValStr.c_str(), O_WRONLY|O_SYNC);
	if (statusVal < 0){
			perror("could not open SYSFS GPIO value device");
        exit(1);
	}
		
	if (val.compare("1") != 0 && val.compare("0") != 0 ) {
		fprintf(stderr, "Invalid  value. Should be \"1\" or \"0\". \n");
		exit(1);
	}
		
	statusVal = write(this->valuefd, val.c_str(), val.length());
	if (statusVal < 0){
		perror("could not write to SYSFS GPIO value device");
        exit(1);
	}
	
	statusVal = close(this->valuefd);
	if (statusVal < 0){
		perror("could not close SYSFS GPIO value device");
        exit(1);
	}

	    return statusVal;
}

int GPIOClass::gpio_set_edge(string gpio, unsigned int edge)
{
  int fd;
  char filename[28];

   snprintf(filename, sizeof(filename), "/sys/class/gpio/gpio%d/edge", stoi(gpio));

   if ((fd = open(filename, O_WRONLY)) < 0)
       return -1;

    write(fd, stredge[edge], strlen(stredge[edge]) + 1);
    close(fd);
	
}

int GPIOClass::add_edge_detect(unsigned int edge)
// return values:
// 0 - Success
// 1 - Edge detection already added
// 2 - Other error
{
    int fd;
 //   pthread_t threads;
    //struct epoll_event ev;
    long t = 0;

    // check to see if this gpio has been added already
   // if (gpio_event_added(gpio) != 0)
    //    return 1;

    // export /sys/class/gpio interface
    //gpio_export(gpio);
	
    this->setdir_gpio("in"); 
    gpio_set_edge( this->gpionum, edge);
	
}

int GPIOClass::getval_gpio(string& val){

	string getValStr = "/sys/class/gpio/gpio" + this->gpionum + "/value";
	char buff[10];
	int statusVal = -1;
	this->valuefd = statusVal = open(getValStr.c_str(), O_RDONLY|O_SYNC);
	if (statusVal < 0){
			perror("could not open SYSFS GPIO value device");
        exit(1);
	}

	statusVal = read(this->valuefd, &buff, 1);
	if (statusVal < 0){
		perror("could not read SYSFS GPIO value device");
        exit(1);
	}
	
	buff[1]='\0';
	
	val = string(buff);
	
	if (val.compare("1") != 0 && val.compare("0") != 0 ) {
		fprintf(stderr, "Invalid  value read. Should be \"1\" or \"0\". \n");
		exit(1);
	}
	
	statusVal = close(this->valuefd);
	if (statusVal < 0){
		perror("could not close SYSFS GPIO value device");
        exit(1);
	}

	return statusVal;
}

string GPIOClass::retval_gpio()
{
	string getValStr = "/sys/class/gpio/gpio" + this->gpionum + "/value";
	char buff[10];
	int statusVal = -1;
	this->valuefd = statusVal = open(getValStr.c_str(), O_RDONLY|O_SYNC);
	if (statusVal < 0){
			perror("could not open SYSFS GPIO value device");
        exit(1);
	}

	statusVal = read(this->valuefd, &buff, 1);
	if (statusVal < 0){
		perror("could not read SYSFS GPIO value device");
        exit(1);
	}
	
	buff[1]='\0';
	
	string val = string(buff);
	
	if (val.compare("1") != 0 && val.compare("0") != 0 ) {
		fprintf(stderr, "Invalid  value read. Should be \"1\" or \"0\". \n");
		exit(1);
	}
	
	statusVal = close(this->valuefd);
	if (statusVal < 0){
		perror("could not close SYSFS GPIO value device");
        exit(1);
	}

	return val;
}

string GPIOClass::get_gpionum(){

return this->gpionum;

}
