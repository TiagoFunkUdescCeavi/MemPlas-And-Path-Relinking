import operator

def table_anova( in1, in2, out1, out2 ):

    fileInput1 = in1
    fileInput2 = in2
    fileOutput1 = out1
    fileOutput2 = out2

    listOfPairs = []
    listOfLines = []

    info_anova = "\caption{Resultados do teste do ANOVA por instância}\n\label{tab:resultados_anova}\n"
    header_anova = "\\begin{table}[htb]\n"+info_anova+"\\begin{tabular}{@{}lr|lr@{}}\n\\toprule\n"
    header_anova += "\multicolumn{2}{c|}{Euclidianas}&\multicolumn{2}{|c}{Não Euclidianas}\\\\"
    header_anova += "Inst\^ancia&p (\%)&Inst\^ancia&p (\%)\\\\\\midrule\n"
    footer_anova = "\\bottomrule\n\end{tabular}\n\end{table}\n"
    content_anova = ""

    #M-MPR&M-OLS&M-PR&MPR-&OLS&MPR-PR&OLS-PR
    info_tukey = "\caption{Resultados do teste de Tukey}\n\label{tab:resultados_tukey}\n"
    header_tukey = "\\begin{landscape}\n\\begin{table}[htb]\n\n"+info_tukey+"\\resizebox{1.8\\textheight}{!}{\n\\begin{tabular}{@{}l|rr|rr|rr@{}}\n\\toprule\n"
    header_tukey += "Instancia&\multicolumn{2}{|c|}{om-pr}&\multicolumn{2}{|c|}{om-ompr}&\multicolumn{2}{|c|}{opr-ompr}\\\\\n"
    header_tukey += "&D.M.&p (\%)&D.M.&p (\%)&\\\\\\midrule\n"
    footer_tukey = "\\bottomrule\n\end{tabular}\n}\n\end{table}\n\end{landscape}\n"
    content_tukey = ""

    class Pair:
        def __init__(self, instance, anova):
            self.instance = instance
            self.anova = anova
        
        def info(self):
            return self.instance + "&" + ("*" if self.anova<5.0 else "") + "{0:3.2f}".format( self.anova )

    def anova_test( line ):
        x = line.split(";")
        listOfPairs.append( Pair( x[0], round( float( x[1] )*100, 2 ) ) )

    def tukey_test( listOfLines, index ):
        content = listOfLines[i-1].split(";")[0] + "&"
        for j in range(4, 7):
            x = listOfLines[ index+j ]
            x = x.split(" ")
            x = [ s.strip() for s in x if s.strip() != ""]
            content += "{0:3.2f}".format( float( x[2] ) ) + "&"
            pvalue = float( x[3] )*100
            content += ("*" if pvalue<10.0 else "") + "{0:3.2f}".format( pvalue ) + "&"
        content = content[ :-1 ] + "\\\\\n"
        return content


    file = open(fileInput1, "r")
    for line in file:
        line = line.replace("\n","")
        listOfLines.append( line )

    file = open(fileInput2, "r")
    for line in file:
        line = line.replace("\n","")
        listOfLines.append( line )

    i = 0
    while( i < len( listOfLines ) ):
        # print( listOfLines[i],"--->",i )
        if listOfLines[i].find("Multiple") != -1:
            content_tukey += tukey_test( listOfLines, i )
            i += 8
        else:
            anova_test( listOfLines[i] )
            i += 1

    listOfPairs.sort(key=operator.attrgetter('instance'))
    for c, p in enumerate( listOfPairs ):
        content_anova += p.info()
        if c % 2 == 0 :
            content_anova += "&"
        else:
            content_anova += "\\\\\n"
    content_anova = content_anova.replace("nan","100.00")

    file = open( fileOutput1, "w")
    file.write( header_anova + content_anova + footer_anova )

    file = open( fileOutput2, "w")
    file.write( header_tukey + content_tukey + footer_tukey )