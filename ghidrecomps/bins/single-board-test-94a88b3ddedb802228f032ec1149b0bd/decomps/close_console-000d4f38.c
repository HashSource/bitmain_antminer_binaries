
undefined4 close_console(void)

{
  int iVar1;
  
  iVar1 = DAT_000d4f70;
  if (*(FILE **)(DAT_000d4f70 + 4) != *DAT_000d4f6c) {
    fclose(*(FILE **)(DAT_000d4f70 + 4));
  }
  if (*(FILE **)(iVar1 + 8) != *DAT_000d4f74) {
    fclose(*(FILE **)(iVar1 + 8));
  }
  CRYPTO_lock(10,0x1f,DAT_000d4f78,0x249);
  return 1;
}

