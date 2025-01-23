```mermaid
graph TD
    A((abcdef)) --> |-ab| B((cdef))
    A --> |-abc| C((def))
    A --> |-abcd| D((ef))

    B --> |-cd| E((ef))

    C --> |-def| F((''))
```