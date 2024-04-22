
char * read_string(scanner_t *s,va_list *ap,char *purpose,size_t *out_len,int *ours)

{
  char cVar1;
  size_t length_00;
  int iVar2;
  char **ppcVar3;
  char *pcVar4;
  size_t *psVar5;
  size_t *out_len_local;
  char *purpose_local;
  va_list *ap_local;
  scanner_t *s_local;
  strbuffer_t strbuff;
  char *str;
  char t;
  size_t length;
  
  next_token(s);
  cVar1 = (s->token).token;
  prev_token(s);
  if (((cVar1 == '#') || (cVar1 == '%')) || (cVar1 == '+')) {
    strbuffer_init(&strbuff);
    do {
      ppcVar3 = (char **)ap->__ap;
      ap->__ap = ppcVar3 + 1;
      pcVar4 = *ppcVar3;
      if (pcVar4 == (char *)0x0) {
        set_error(s,"<args>","NULL string argument");
        strbuffer_close(&strbuff);
        return (char *)0x0;
      }
      next_token(s);
      if ((s->token).token == '#') {
        psVar5 = (size_t *)ap->__ap;
        ap->__ap = psVar5 + 1;
        length = *psVar5;
      }
      else if ((s->token).token == '%') {
        psVar5 = (size_t *)ap->__ap;
        ap->__ap = psVar5 + 1;
        length = *psVar5;
      }
      else {
        prev_token(s);
        length = strlen(pcVar4);
      }
      iVar2 = strbuffer_append_bytes(&strbuff,pcVar4,length);
      if (iVar2 == -1) {
        set_error(s,"<internal>","Out of memory");
        strbuffer_close(&strbuff);
        return (char *)0x0;
      }
      next_token(s);
    } while ((s->token).token == '+');
    prev_token(s);
    iVar2 = utf8_check_string(strbuff.value,strbuff.length);
    if (iVar2 == 0) {
      set_error(s,"<args>","Invalid UTF-8 %s",purpose);
      strbuffer_close(&strbuff);
      pcVar4 = (char *)0x0;
    }
    else {
      *out_len = strbuff.length;
      *ours = 1;
      pcVar4 = strbuffer_steal_value(&strbuff);
    }
  }
  else {
    ppcVar3 = (char **)ap->__ap;
    ap->__ap = ppcVar3 + 1;
    pcVar4 = *ppcVar3;
    if (pcVar4 == (char *)0x0) {
      set_error(s,"<args>","NULL string argument");
      pcVar4 = (char *)0x0;
    }
    else {
      length_00 = strlen(pcVar4);
      iVar2 = utf8_check_string(pcVar4,length_00);
      if (iVar2 == 0) {
        set_error(s,"<args>","Invalid UTF-8 %s",purpose);
        pcVar4 = (char *)0x0;
      }
      else {
        *out_len = length_00;
        *ours = 0;
      }
    }
  }
  return pcVar4;
}

