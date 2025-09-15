
void smtp_perform_rcpt_to(int *param_1)

{
  int iVar1;
  char *pcVar2;
  
  if (*(char *)**(undefined4 **)(*(int *)(*param_1 + 0x14c) + 8) == '<') {
    pcVar2 = "RCPT TO:%s";
  }
  else {
    pcVar2 = "RCPT TO:<%s>";
  }
  iVar1 = Curl_pp_sendf(param_1 + 0xf0,pcVar2);
  if (iVar1 == 0) {
    param_1[0xfe] = 9;
  }
  return;
}

