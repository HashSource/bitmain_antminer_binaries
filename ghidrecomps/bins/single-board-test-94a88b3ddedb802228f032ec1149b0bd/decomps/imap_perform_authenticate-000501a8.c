
void imap_perform_authenticate(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 != 0) {
    imap_sendf(param_1,"AUTHENTICATE %s %s",param_2);
    return;
  }
  imap_sendf(param_1,"AUTHENTICATE %s",param_2);
  return;
}

