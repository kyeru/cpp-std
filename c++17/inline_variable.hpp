namespace myspace {

// commenting "inline" keyword out below causes multiple definition error
inline int inline_var = 0;

inline int return_inline_var() {
    return inline_var;
}

}
