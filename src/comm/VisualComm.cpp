#include "../../include/comm/VisualComm.h"
#include <Arduino.h>

extern unsigned int __bss_end;   // Symbol marking the end of the .bss section (static & global variables in RAM).
extern void *__brkval;           // Current end of the heap. NULL (0) if no malloc() has been used yet.

void VisualComm::print_free_memory(char *currentMethodPtr) {
  int free_memory;

  // If the heap hasn't been used (__brkval == 0)
  if ((int)__brkval == 0) {
    // free space = (address of local var / stack pointer) - (end of bss section)
    free_memory = ((int)&free_memory) - ((int)&__bss_end);
  } else {
    // Otherwise, heap is in use
    // free space = (address of local var / stack pointer) - (current end of heap)
    free_memory = ((int)&free_memory) - ((int)__brkval);
  }

  print(currentMethodPtr);  
  print(" Free Memory: ");
  print(free_memory);
  print_line(" bytes");
}

void VisualComm::print_terminal_logo() {
  print_line(F(" *************************  **                                **  ************************* "));
  print_line(F(" *************************  **     **********************     **  ************************* "));
  print_line(F(" ***********************  **     **************************     **  *********************** "));
  print_line(F(" *********************  **     ******************************    **  ********************** "));
  print_line(F(" *******************  **     **********************************    **  ******************** "));
  print_line(F(" *****************  **     **************************************    **  ****************** "));
  print_line(F(" ***************  **     ******************************************     **  *************** "));
  print_line(F("                 **    **********************************************     **                "));
  print_line(F(" ************** **     **********************************************     ** ************** "));
  print_line(F(" ************** **     **********************************************     ** ************** "));
  print_line(F(" ************** **     ****  C Y C L O B O T   O L U S O G B A  *****     ** ************** "));
  print_line(F(" ************** **     **********************************************     ** ************** "));
  print_line(F(" ************** **     **********************************************     ** ************** "));
  print_line(F("                **     **********************************************     **                "));
  print_line(F(" ***************  **     ******************************************     **  *************** "));
  print_line(F(" *****************  **     **************************************     **  ***************** "));
  print_line(F(" *******************  **     **********************************     **  ******************* "));
  print_line(F(" *********************  **     ******************************     **  ********************* "));
  print_line(F(" ***********************  **     **************************     **  *********************** "));
  print_line(F(" *************************  **     **********************     **  ************************* "));
  print_line(F(" *************************  **                                **  ************************* "));
}