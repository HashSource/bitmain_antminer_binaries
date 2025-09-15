
void prev_token(scanner_t *s)

{
  char cVar1;
  undefined3 uVar2;
  int iVar3;
  size_t sVar4;
  scanner_t *s_local;
  
  iVar3 = (s->token).column;
  sVar4 = (s->token).pos;
  cVar1 = (s->token).token;
  uVar2 = *(undefined3 *)&(s->token).field_0xd;
  (s->next_token).line = (s->token).line;
  (s->next_token).column = iVar3;
  (s->next_token).pos = sVar4;
  (s->next_token).token = cVar1;
  *(undefined3 *)&(s->next_token).field_0xd = uVar2;
  iVar3 = (s->prev_token).column;
  sVar4 = (s->prev_token).pos;
  cVar1 = (s->prev_token).token;
  uVar2 = *(undefined3 *)&(s->prev_token).field_0xd;
  (s->token).line = (s->prev_token).line;
  (s->token).column = iVar3;
  (s->token).pos = sVar4;
  (s->token).token = cVar1;
  *(undefined3 *)&(s->token).field_0xd = uVar2;
  return;
}

