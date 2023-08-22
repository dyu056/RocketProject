//SIMPLE WRITE AND READ

#include <SPI.h>   //sd cARD USES spi bUS
#include <SD.h>    //contains library functions

#define CSPIN 4   //slecting DPin-4 does not require to set direction
File myFile;      //file pointer variavle declaration

void setup()
{
  Serial.begin(9600);
  Serial.print("inizialization SD... ");

  if (!SD.begin(4))
  {
    Serial.println("inizialization failed!");
    while (1);
  }
  Serial.println("inizialization complete.");
  SD.remove("Test2.txt"); //remove any existing file with this name
  myFile = SD.open("Test2.txt", FILE_WRITE);  //file created and opened for writing

  if (myFile)       //file has really been opened
  {
    myFile.println("Arduino");
    myFile.close();

  }
  myFile = SD.open("Test2.txt", FILE_READ);  //file created and opened for writing

  if (myFile)       //file has really been opened
  {
    while (myFile.available())
    {
      Serial.print((char)myFile.read());
    }
    myFile.close();
  }
}

void loop()
{

}
