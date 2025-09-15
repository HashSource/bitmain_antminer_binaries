
api_data * api_add_extra(api_data *root,api_data *extra)

{
  api_data *paVar1;
  api_data *extra_local;
  api_data *root_local;
  api_data *tmp;
  
  root_local = extra;
  if ((root != (api_data *)0x0) && (root_local = root, extra != (api_data *)0x0)) {
    paVar1 = extra->prev;
    extra->prev = root->prev;
    root->prev->next = extra;
    paVar1->next = root;
    root->prev = paVar1;
  }
  return root_local;
}

