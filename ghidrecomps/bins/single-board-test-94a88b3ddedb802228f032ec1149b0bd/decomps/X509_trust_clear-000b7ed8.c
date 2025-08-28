
void X509_trust_clear(X509 *x)

{
  _STACK *st;
  
  if ((*(undefined4 **)(x->sha1_hash + 0xc) != (undefined4 *)0x0) &&
     (st = (_STACK *)**(undefined4 **)(x->sha1_hash + 0xc), st != (_STACK *)0x0)) {
    sk_pop_free(st,(func *)0xb543d);
    **(undefined4 **)(x->sha1_hash + 0xc) = 0;
  }
  return;
}

