//karol_mirek
//301650

#ifndef HELPERS_H
#define HELPERS_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <string>
#include <deque>
#include <fstream>


u_int32_t how_many_packets(u_int32_t);
void window_setup();
bool is_number(std::string str);
void valid_input(int length, char* argv[]);
void write_to_file(std::string filename);


#endif
