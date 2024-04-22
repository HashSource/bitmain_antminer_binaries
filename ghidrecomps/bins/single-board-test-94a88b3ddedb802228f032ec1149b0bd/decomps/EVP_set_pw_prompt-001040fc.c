
void EVP_set_pw_prompt(char *prompt)

{
  char *pcVar1;
  
  pcVar1 = DAT_0010411c;
  if (prompt != (char *)0x0) {
    strncpy(DAT_0010411c,prompt,0x4f);
    pcVar1[0x4f] = '\0';
    return;
  }
  *DAT_0010411c = '\0';
  return;
}

