
void CRYPTO_lock_part_0(void)

{
  int extraout_r0;
  undefined4 in_r3;
  undefined1 unaff_r4;
  int unaff_r5;
  
  OpenSSLDie("cryptlib.c",0x24d,"pointer != NULL");
  *(undefined1 *)(unaff_r5 + 0x17) = unaff_r4;
  *(char *)(extraout_r0 + 0x19) = (char)extraout_r0;
  __libc_start_main(0x4b4cd,in_r3,&stack0xfffffffc,0x1d2f5d,0x1d2f9d,extraout_r0,&stack0xfffffffc);
                    /* WARNING: Subroutine does not return */
  abort();
}

