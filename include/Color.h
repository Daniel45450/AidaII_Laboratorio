#ifndef COLOR_H
#define COLOR_H


class Color
{
    public:
        Color();
        virtual ~Color();
        Color(int r, int g, int b);
        void modificar_color(int r, int g, int b);
        bool operator<(const Color & color_a) const;
        bool operator==(const Color& color_a) const;
        bool operator!=(const Color& color_a) const;
        Color& operator=(const Color& b);
        int obtener_RED() const;
        int obtener_GREEN() const;
        int obtener_BLUE() const;

    protected:

    private:
        int r;
        int b;
        int g;
};

#endif // COLOR_H
