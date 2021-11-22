# Assignment 6- Public Key Cryptography

Description: This program will demonstrate the encryption and decryption of private and public keys using the RSA algorithm. The keys represent shared data between two parties that can be shared publicly in the form of two keys. This program will generate public and private keys along with encoding and decoding the keys using GNU libraries of high math precision to be utilized. SSH key generation and sharing of keys allows for highly sensitive information to be shared in a secure manner by using power mod.

## Building

Files

Makefile: 
• CC = clang must be specified.
• CFLAGS = -Wall -Wextra -Werror -Wpedantic must be specified. 
• pkg-config to locate compilation and include flags for the GMP library must be used. 
• make must build the encrypt, decrypt, and keygen executables, as should make all. 
• make decrypt should build only the decrypt program. 
• make encrypt should build only the encrypt program. 
• make keygen should build only the keygen program. 
• make clean must remove all files that are compiler generated. 
• make format should format all your source code, including the header files. 

README.md: This must use proper Markdown syntax and describe how to use your program and Makefile. It should also list and explain any command-line options that your program accepts. Any false positives reported by scan-build should be documented and explained here as well

DESIGN.pdf: This document must be a proper PDF. This design document must describe your design and design process for your program with enough detail such that a sufficiently knowledgeable programmer would be able to replicate your implementation. 

decrypt.c: This contains the implementation and main() function for the decrypt program. 

encrypt.c: This contains the implementation and main() function for the encrypt program. 

keygen.c: This contains the implementation and main() function for the keygen program. 

numtheory.c: This contains the implementations of the number theory functions. 

numtheory.h: This specifies the interface for the number theory functions. 

randstate.c: This contains the implementation of the random state interface for the RSA library and number theory functions.

randstate.h: This specifies the interface for initializing and clearing the random state. 

rsa.c: This contains the implementation of the RSA library. 

rsa.h: This specifies the interface for the RSA library

## INSTRUCTIONS

This program is intended to be run in the Ubuntu Virtual Box with PuTTY and in order to run program you will be given a list of commands when running the program using '-h'.You will have to first generate keys to encrypt and decrypt a given input file by running ./keygen. Ercrypt files using ./dencrypt. Then specify encrypt input file by using -i and specify the encrypted outfile with -o along with a specified -n pubfile. To decrypt the given outfile use ./decrypt along with -i encrypted file and -o to write out the decrypted file to. The -v command will allow for user the see the stats such as bits involved with variables.
