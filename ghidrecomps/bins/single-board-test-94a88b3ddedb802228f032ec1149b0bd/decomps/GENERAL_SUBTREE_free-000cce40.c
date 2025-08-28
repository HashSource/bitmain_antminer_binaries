
void GENERAL_SUBTREE_free(GENERAL_SUBTREE *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)GENERAL_SUBTREE_it);
  return;
}

