
/* WARNING: Unknown calling convention */

char * read_string(scanner_t *s,va_list *ap,char *purpose,int *ours)

{
  byte bVar1;
  char cVar2;
  undefined3 uVar3;
  int iVar4;
  size_t sVar5;
  size_t size;
  undefined4 *puVar6;
  token_t *ptVar7;
  token_t *ptVar8;
  token_t *ptVar9;
  char *pcVar10;
  strbuffer_t strbuff;
  
  ptVar7 = &s->token;
  ptVar9 = &s->next_token;
  next_token(s);
  iVar4 = (s->token).column;
  sVar5 = (s->token).pos;
  cVar2 = (s->token).token;
  uVar3 = *(undefined3 *)&(s->token).field_0xd;
  ptVar8 = &s->prev_token;
  bVar1 = (s->token).token;
  ptVar9->line = ptVar7->line;
  (s->next_token).column = iVar4;
  (s->next_token).pos = sVar5;
  (s->next_token).token = cVar2;
  *(undefined3 *)&(s->next_token).field_0xd = uVar3;
  iVar4 = (s->prev_token).column;
  sVar5 = (s->prev_token).pos;
  cVar2 = (s->prev_token).token;
  uVar3 = *(undefined3 *)&(s->prev_token).field_0xd;
  ptVar7->line = ptVar8->line;
  (s->token).column = iVar4;
  (s->token).pos = sVar5;
  (s->token).token = cVar2;
  *(undefined3 *)&(s->token).field_0xd = uVar3;
  if ((bVar1 & 0xf7) == 0x23) {
    strbuffer_init(&strbuff);
    do {
      puVar6 = (undefined4 *)ap->__ap;
      ap->__ap = puVar6 + 1;
      pcVar10 = (char *)*puVar6;
      if (pcVar10 == (char *)0x0) {
        set_error(s,"<args>","NULL string argument");
        strbuffer_close(&strbuff);
        return (char *)0x0;
      }
      next_token(s);
      if ((s->token).token == '#') {
                    /* WARNING: Load size is inaccurate */
        size = *ap->__ap;
        ap->__ap = (size_t *)((int)ap->__ap + 4);
      }
      else {
        iVar4 = (s->token).column;
        sVar5 = (s->token).pos;
        cVar2 = (s->token).token;
        uVar3 = *(undefined3 *)&(s->token).field_0xd;
        ptVar9->line = ptVar7->line;
        (s->next_token).column = iVar4;
        (s->next_token).pos = sVar5;
        (s->next_token).token = cVar2;
        *(undefined3 *)&(s->next_token).field_0xd = uVar3;
        iVar4 = (s->prev_token).column;
        sVar5 = (s->prev_token).pos;
        cVar2 = (s->prev_token).token;
        uVar3 = *(undefined3 *)&(s->prev_token).field_0xd;
        ptVar7->line = ptVar8->line;
        (s->token).column = iVar4;
        (s->token).pos = sVar5;
        (s->token).token = cVar2;
        *(undefined3 *)&(s->token).field_0xd = uVar3;
        size = strlen(pcVar10);
      }
      iVar4 = strbuffer_append_bytes(&strbuff,pcVar10,size);
      if (iVar4 == -1) {
        set_error(s,"<internal>","Out of memory");
        strbuffer_close(&strbuff);
        return (char *)0x0;
      }
      next_token(s);
    } while ((s->token).token == '+');
    iVar4 = (s->token).column;
    sVar5 = (s->token).pos;
    cVar2 = (s->token).token;
    uVar3 = *(undefined3 *)&(s->token).field_0xd;
    ptVar9->line = ptVar7->line;
    (s->next_token).column = iVar4;
    (s->next_token).pos = sVar5;
    (s->next_token).token = cVar2;
    *(undefined3 *)&(s->next_token).field_0xd = uVar3;
    iVar4 = (s->prev_token).column;
    sVar5 = (s->prev_token).pos;
    cVar2 = (s->prev_token).token;
    uVar3 = *(undefined3 *)&(s->prev_token).field_0xd;
    ptVar7->line = ptVar8->line;
    (s->token).column = iVar4;
    (s->token).pos = sVar5;
    (s->token).token = cVar2;
    *(undefined3 *)&(s->token).field_0xd = uVar3;
    pcVar10 = strbuffer_steal_value(&strbuff);
    iVar4 = utf8_check_string(pcVar10,-1);
    if (iVar4 != 0) {
      *ours = 1;
      return pcVar10;
    }
  }
  else {
    puVar6 = (undefined4 *)ap->__ap;
    ap->__ap = puVar6 + 1;
    pcVar10 = (char *)*puVar6;
    if (pcVar10 == (char *)0x0) {
      set_error(s,"<args>","NULL string argument");
      return (char *)0x0;
    }
    iVar4 = utf8_check_string(pcVar10,-1);
    if (iVar4 != 0) {
      *ours = 0;
      return pcVar10;
    }
  }
  set_error(s,"<args>","Invalid UTF-8 %s",purpose);
  return (char *)0x0;
}

