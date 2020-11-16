// Assignment 4 Problem 4
// function testBigEndian tests whether a processor stores most significant byte of a 4-byte integer
// in the lowest memory address
// if the result is true the processor is Big Endian
// if the result is false the processor is Little Endian
int testBigEndian(void)
{
  static int testInt = 0xDEADBEEF;
  unsigned char byte1, byte2, byte3, byte4;
  int result = 0;
  //
  //
  byte1 = *((unsigned char *)&testInt);
  byte2 = *((unsigned char *)&testInt + 1);
  byte3 = *((unsigned char *)&testInt + 2);
  byte4 = *((unsigned char *)&testInt + 3);
  if (byte1 == 222)  //  222 = 0xDE
  {
      result = 1;
  }
  else
  {
      result = 0;
  }
  return result;
}

int main()
{
  int testResult = 0;
  testResult = testBigEndian();
  return 0;
}