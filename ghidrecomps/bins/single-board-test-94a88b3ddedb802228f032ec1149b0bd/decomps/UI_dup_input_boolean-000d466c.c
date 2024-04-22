
int UI_dup_input_boolean
              (UI *ui,char *prompt,char *action_desc,char *ok_chars,char *cancel_chars,int flags,
              char *result_buf)

{
  char *ptr;
  int iVar1;
  
  if (prompt == (char *)0x0) {
    ptr = (char *)0x0;
  }
  else {
    ptr = BUF_strdup(prompt);
    if (ptr == (char *)0x0) {
      ERR_put_error(0x28,0x6e,0x41,DAT_000d4730,0x134);
      return -1;
    }
  }
  if ((action_desc != (char *)0x0) &&
     (action_desc = BUF_strdup(action_desc), action_desc == (char *)0x0)) {
    ERR_put_error(0x28,0x6e,0x41,DAT_000d4730,0x13c);
    ok_chars = (char *)0x0;
    goto LAB_000d46e8;
  }
  if (ok_chars == (char *)0x0) {
LAB_000d46a8:
    if ((cancel_chars == (char *)0x0) ||
       (cancel_chars = BUF_strdup(cancel_chars), cancel_chars != (char *)0x0)) {
      iVar1 = general_allocate_boolean_constprop_3
                        (ui,ptr,action_desc,ok_chars,cancel_chars,1,flags,result_buf);
      return iVar1;
    }
    iVar1 = 0x14c;
  }
  else {
    ok_chars = BUF_strdup(ok_chars);
    iVar1 = 0x144;
    if (ok_chars != (char *)0x0) goto LAB_000d46a8;
  }
  ERR_put_error(0x28,0x6e,0x41,DAT_000d4730,iVar1);
LAB_000d46e8:
  if (ptr != (char *)0x0) {
    CRYPTO_free(ptr);
  }
  if (action_desc != (char *)0x0) {
    CRYPTO_free(action_desc);
  }
  if (ok_chars != (char *)0x0) {
    CRYPTO_free(ok_chars);
  }
  return -1;
}

