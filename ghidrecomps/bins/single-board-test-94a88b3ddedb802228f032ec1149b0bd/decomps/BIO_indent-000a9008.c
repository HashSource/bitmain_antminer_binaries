
int BIO_indent(BIO *b,int indent,int max)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = indent & ~(indent >> 0x1f);
  if (max <= (int)uVar2) {
    uVar2 = max;
  }
  do {
    if (uVar2 == 0) {
      return 1;
    }
    iVar1 = BIO_puts(b,DAT_000a9034);
    uVar2 = uVar2 - 1;
  } while (iVar1 == 1);
  return 0;
}

