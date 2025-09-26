
UI_METHOD * UI_set_method(UI *ui,UI_METHOD *meth)

{
  *(UI_METHOD **)ui = meth;
  return meth;
}

