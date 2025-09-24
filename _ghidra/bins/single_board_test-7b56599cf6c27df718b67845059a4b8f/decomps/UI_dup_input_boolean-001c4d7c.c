
int UI_dup_input_boolean
              (UI *ui,char *prompt,char *action_desc,char *ok_chars,char *cancel_chars,int flags,
              char *result_buf)

{
  char *ptr;
  char *pcVar1;
  int iVar2;
  
  if (prompt == (char *)0x0) {
    ptr = (char *)0x0;
  }
  else {
    ptr = CRYPTO_strdup(prompt,"crypto/ui/ui_lib.c",0x110);
    if (ptr == (char *)0x0) {
      ERR_put_error(0x28,0x6e,0x41,"crypto/ui/ui_lib.c",0x112);
      ok_chars = (char *)0x0;
      action_desc = (char *)0x0;
      goto LAB_001c4e2c;
    }
  }
  if ((action_desc != (char *)0x0) &&
     (action_desc = CRYPTO_strdup(action_desc,"crypto/ui/ui_lib.c",0x118),
     action_desc == (char *)0x0)) {
    ERR_put_error(0x28,0x6e,0x41,"crypto/ui/ui_lib.c",0x11a);
    ok_chars = (char *)0x0;
    goto LAB_001c4e2c;
  }
  if (ok_chars == (char *)0x0) {
LAB_001c4ddc:
    if (cancel_chars == (char *)0x0) {
      pcVar1 = (char *)0x0;
LAB_001c4df2:
      iVar2 = general_allocate_boolean_constprop_4
                        (ui,ptr,action_desc,ok_chars,pcVar1,1,flags,result_buf);
      return iVar2;
    }
    pcVar1 = CRYPTO_strdup(cancel_chars,"crypto/ui/ui_lib.c",0x128);
    if (pcVar1 != (char *)0x0) goto LAB_001c4df2;
    iVar2 = 0x12a;
  }
  else {
    ok_chars = CRYPTO_strdup(ok_chars,"crypto/ui/ui_lib.c",0x120);
    iVar2 = 0x122;
    if (ok_chars != (char *)0x0) goto LAB_001c4ddc;
  }
  ERR_put_error(0x28,0x6e,0x41,"crypto/ui/ui_lib.c",iVar2);
LAB_001c4e2c:
  CRYPTO_free(ptr);
  CRYPTO_free(action_desc);
  CRYPTO_free(ok_chars);
  CRYPTO_free((void *)0x0);
  return -1;
}

