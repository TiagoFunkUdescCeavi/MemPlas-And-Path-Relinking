import sys

fileInput = sys.argv[1]
fileOutput = sys.argv[2]
caption = sys.argv[3]
label = sys.argv[4]

caption = caption.replace("_","\_")
label = label.replace("_","\_")

info = "\caption{"+caption+"}\n\label{tab:"+label+"}\n"
header = "\\begin{landscape}\n\\begin{table}[htb]\n\n"+info+"\\resizebox{1.8\\textheight}{!}{\n\\begin{tabular}{@{}lr|rr|rr|rr|rr|rr|rr|rr@{}}\\toprule\n"
header += """\multicolumn{2}{c|}{}&\multicolumn{2}{c|}{}&\multicolumn{2}{c|}{}&
                \multicolumn{2}{c|}{Memplas}&\multicolumn{2}{c|}{}&
                \multicolumn{2}{c|}{Memplas}&\multicolumn{2}{c|}{Memplas}&\multicolumn{2}{c}{Memplas}\\\\
            \multicolumn{2}{c|}{}&\multicolumn{2}{c|}{Memplas}&\multicolumn{2}{c|}{Memplas}&
                \multicolumn{2}{c|}{Plasmídeo +}&\multicolumn{2}{c|}{Somente}&
                \multicolumn{2}{c|}{Apenas}&\multicolumn{2}{c|}{Apenas}&\multicolumn{2}{c}{Apenas Plasmídeo}\\\\
            \multicolumn{2}{c|}{Problemas}&\multicolumn{2}{c|}{Plasmídeo}&\multicolumn{2}{c|}{Path Relinking}&
                \multicolumn{2}{c|}{Path Relinking.}&\multicolumn{2}{c|}{Buscas locais}&
                \multicolumn{2}{c|}{Plasmídeo}&\multicolumn{2}{c|}{Path Relinking}&\multicolumn{2}{c}{+ Path Relinking}\\\\"""
# header += "\multicolumn{2}{c|}{}&\multicolumn{2}{c|}{MemPlas}&\multicolumn{2}{c|}{MemPlas}&\multicolumn{2}{c|}{Somente}&\multicolumn{2}{c}{Memplas}\\"
# header += "\multicolumn{2}{c|}{Problemas}&\multicolumn{2}{c|}{Plasmídeo}&\multicolumn{2}{c|}{Plasm. + Path Rel.}&\multicolumn{2}{c|}{Buscas Locais}&\multicolumn{2}{c}{Path Relinking}\\"
# header += "\multicolumn{2}{c|}{Problemas}&\multicolumn{2}{c|}{Memplas}&\multicolumn{2}{c|}{Path Relinking}&\multicolumn{2}{c|}{Memplas + Path R.}&"
# header += "\multicolumn{2}{c|}{Buscas locais}&\multicolumn{2}{c|}{Apenas Memplas}&\multicolumn{2}{c|}{Apenas M e PR}&\multicolumn{2}{c|}{Apenas PR}\\\\\\midrule\n"
footer = "\\bottomrule\n\end{tabular}\n}\n\end{table}\n\end{landscape}\n"

with open(fileOutput, 'w') as output:
    with open(fileInput) as fp:
        output.write( header )
        for cnt, line in enumerate(fp):
            line = line.replace(",","&").replace("\n","\\\\\n").replace("_","\_")
            if cnt == 0 :
                output.write( line.replace("\n","\midrule\n") )
            else:
                output.write( line )
        output.write( footer )