/*
lexp -> número | (op lexp-seq)
op -> +|-|*
lexp-seq -> lexp-seq lexp | lexp
*/

typedef enum
{
    Plus,  // Operador   +
    Minus, // Operador   -
    Mult   // Operador   *
} OpKind;

typedef enum
{
    OpK,     // um OpKind
    ConstK,  // um Número
    LexpSeqK // um LexpSeqKind
} LexpKind;

typedef enum
{
    LexpK // um LexpKind
} LexpSeqKind;


/* a estrutura de um nó da árvore. Nessa árvore podemos ter OpKind, LexpKind, LexpSeqKind e um Value que representa
os números. */
typedef struct streeNode
{
    OpKind op;
    LexpKind lexp;
    LexpSeqKind LexpSeq;
    int Value; // é a contante, no caso o número.
    struct streetnode *leftchild, *rightchild; 
} STreeNode;
typedef STreeNode *SyntaxTree;
