#include <stdio.h>
#include <math.h>
#include "conversor.h"

int quase_igual(double a, double b) {
    return fabs(a - b) < 0.01;
}

int main() {
    int falhas = 0;

    // Caso de Teste 1: Celsius para Fahrenheit (0°C = 32°F e 100°C = 212°F)
    double res1_a = celsius_para_fahrenheit(0.0);
    double res1_b = celsius_para_fahrenheit(100.0);
    int passou_t1 = quase_igual(res1_a, 32.0) && quase_igual(res1_b, 212.0);
    if (!passou_t1) falhas++;

    // Caso de Teste 2: Fahrenheit para Celsius (32°F = 0°C e 212°F = 100°C)
    double res2_a = fahrenheit_para_celsius(32.0);
    double res2_b = fahrenheit_para_celsius(212.0);
    int passou_t2 = quase_igual(res2_a, 0.0) && quase_igual(res2_b, 100.0);
    if (!passou_t2) falhas++;

    FILE *xml = fopen("test-results.xml", "w");
    if (xml != NULL) {
        fprintf(xml, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
        fprintf(xml, "<testsuite name=\"ConversorTemperaturaTests\" tests=\"2\" failures=\"%d\">\n", falhas);

        fprintf(xml, "  <testcase classname=\"ConversorTest\" name=\"testCelsiusParaFahrenheit\">\n");
        if (!passou_t1) {
            fprintf(xml, "    <failure message=\"Esperado 32.0 e 212.0, obtido %.2f e %.2f\"/>\n", res1_a, res1_b);
        }
        fprintf(xml, "  </testcase>\n");

        fprintf(xml, "  <testcase classname=\"ConversorTest\" name=\"testFahrenheitParaCelsius\">\n");
        if (!passou_t2) {
            fprintf(xml, "    <failure message=\"Esperado 0.0 e 100.0, obtido %.2f e %.2f\"/>\n", res2_a, res2_b);
        }
        fprintf(xml, "  </testcase>\n");

        fprintf(xml, "</testsuite>\n");
        fclose(xml);
    }

    printf("Testes finalizados. Total de falhas: %d\n", falhas);
    return 0; // Retorna 0 para que o Jenkins avalie o XML e marque como UNSTABLE em caso de falha
}