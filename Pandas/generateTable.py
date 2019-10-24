import sys

fileInput = sys.argv[1]
fileOutput = sys.argv[2]
caption = sys.argv[3]
label = sys.argv[4]

caption = caption.replace("_","\_")
label = label.replace("_","\_")

info = "\caption{"+caption+"}\n\label{tab:"+label+"}\n"
header = "\\begin{landscape}\n\\begin{table}[htb]\n\n"+info+"\\begin{tabular}{@{}lrrrrrrrrr@{}}\n\\toprule\n"
footer = "\\bottomrule\n\end{tabular}\n\end{table}\n\end{landscape}\n"

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