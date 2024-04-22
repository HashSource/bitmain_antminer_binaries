
void CRYPTO_lock_part_0(void)

{
  undefined4 in_r3;
  int unaff_r7;
  undefined auStack_4 [4];
  
  OpenSSLDie(DAT_00012708,0x24d,DAT_0001270c);
  __libc_start_main(DAT_00012738,in_r3,auStack_4,DAT_0001273c,DAT_00012734,
                    *(undefined4 *)(unaff_r7 + 0x70),auStack_4);
                    /* WARNING: Subroutine does not return */
  abort();
}

