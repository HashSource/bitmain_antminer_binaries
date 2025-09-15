
void CRYPTO_lock_part_0(void)

{
  undefined4 in_r3;
  int unaff_r7;
  
  OpenSSLDie("cryptlib.c",0x24d,"pointer != NULL");
  __libc_start_main(0x32ac5,in_r3,&stack0xfffffffc,0x12cf35,0x12cf75,
                    *(undefined4 *)(unaff_r7 + 0x70),&stack0xfffffffc);
                    /* WARNING: Subroutine does not return */
  abort();
}

