
int DSO_flags(DSO *dso)

{
  if (dso != (DSO *)0x0) {
    dso = (DSO *)dso->flags;
  }
  return (int)dso;
}

