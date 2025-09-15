
void next_token(scanner_t *s)

{
  char cVar1;
  undefined3 uVar2;
  int iVar3;
  size_t sVar4;
  scanner_t *s_local;
  char *t;
  
  iVar3 = (s->token).column;
  sVar4 = (s->token).pos;
  cVar1 = (s->token).token;
  uVar2 = *(undefined3 *)&(s->token).field_0xd;
  (s->prev_token).line = (s->token).line;
  (s->prev_token).column = iVar3;
  (s->prev_token).pos = sVar4;
  (s->prev_token).token = cVar1;
  *(undefined3 *)&(s->prev_token).field_0xd = uVar2;
  if ((s->next_token).line == 0) {
    t = s->fmt;
    s->column = s->column + 1;
    s->pos = s->pos + 1;
    for (; (((*t == ' ' || (*t == '\t')) || (*t == '\n')) || ((*t == ',' || (*t == ':'))));
        t = t + 1) {
      if (*t == '\n') {
        s->line = s->line + 1;
        s->column = 1;
      }
      else {
        s->column = s->column + 1;
      }
      s->pos = s->pos + 1;
    }
    (s->token).token = *t;
    (s->token).line = s->line;
    (s->token).column = s->column;
    (s->token).pos = s->pos;
    s->fmt = t + 1;
  }
  else {
    iVar3 = (s->next_token).column;
    sVar4 = (s->next_token).pos;
    cVar1 = (s->next_token).token;
    uVar2 = *(undefined3 *)&(s->next_token).field_0xd;
    (s->token).line = (s->next_token).line;
    (s->token).column = iVar3;
    (s->token).pos = sVar4;
    (s->token).token = cVar1;
    *(undefined3 *)&(s->token).field_0xd = uVar2;
    (s->next_token).line = 0;
  }
  return;
}

