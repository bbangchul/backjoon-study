a[7];
main(t)
{
    while (~scanf("%d", a))
        t = fmax(t, a[*a]++ * 9 + *a);
    printf((t < 9) + "1%d%0*d0", t % 9, t / 9, 0);
}