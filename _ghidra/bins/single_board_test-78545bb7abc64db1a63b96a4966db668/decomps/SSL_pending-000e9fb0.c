
int SSL_pending(SSL *s)

{
  uint uVar1;
  
  uVar1 = (**(code **)(s->type + 0x54))();
  if (0x7ffffffe < uVar1) {
    uVar1 = 0x7fffffff;
  }
  return uVar1;
}

