
/* WARNING: Unknown calling convention */

void next_token(scanner_t *s)

{
  char cVar1;
  undefined3 uVar2;
  int iVar3;
  size_t sVar4;
  char *t;
  char *pcVar5;
  int iVar6;
  
  iVar6 = (s->next_token).line;
  iVar3 = (s->token).column;
  sVar4 = (s->token).pos;
  cVar1 = (s->token).token;
  uVar2 = *(undefined3 *)&(s->token).field_0xd;
  (s->prev_token).line = (s->token).line;
  (s->prev_token).column = iVar3;
  (s->prev_token).pos = sVar4;
  (s->prev_token).token = cVar1;
  *(undefined3 *)&(s->prev_token).field_0xd = uVar2;
  if (iVar6 != 0) {
    iVar3 = (s->next_token).line;
    iVar6 = (s->next_token).column;
    sVar4 = (s->next_token).pos;
    cVar1 = (s->next_token).token;
    uVar2 = *(undefined3 *)&(s->next_token).field_0xd;
    (s->next_token).line = 0;
    (s->token).line = iVar3;
    (s->token).column = iVar6;
    (s->token).pos = sVar4;
    (s->token).token = cVar1;
    *(undefined3 *)&(s->token).field_0xd = uVar2;
    return;
  }
  iVar3 = s->line;
  sVar4 = s->pos + 1;
  s->column = s->column + 1;
  s->pos = sVar4;
  pcVar5 = s->fmt;
  do {
    cVar1 = *pcVar5;
    if (cVar1 == ' ' || cVar1 == '\t') {
      if (cVar1 != '\n') goto LAB_0003b892;
LAB_0003b8ae:
      iVar3 = iVar3 + 1;
      s->column = 1;
      s->line = iVar3;
    }
    else {
      if (cVar1 == '\n') goto LAB_0003b8ae;
      if ((cVar1 != ',') && (cVar1 != ':')) {
        iVar6 = s->column;
        s->fmt = pcVar5 + 1;
        (s->token).token = cVar1;
        (s->token).line = iVar3;
        (s->token).pos = sVar4;
        (s->token).column = iVar6;
        return;
      }
LAB_0003b892:
      s->column = s->column + 1;
    }
    sVar4 = sVar4 + 1;
    s->pos = sVar4;
    pcVar5 = pcVar5 + 1;
  } while( true );
}

