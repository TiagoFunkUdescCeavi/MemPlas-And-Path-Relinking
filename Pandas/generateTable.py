
def generateTable( data, caption, label, file_output ):
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
                \multicolumn{2}{c|}{Path Relinking}&\multicolumn{2}{c|}{Buscas locais}&
                \multicolumn{2}{c|}{Plasmídeo}&\multicolumn{2}{c|}{Path Relinking}&\multicolumn{2}{c}{+ Path Relinking}
                \\\\\n"""
    footer = "\\bottomrule\n\end{tabular}\n}\n\end{table}\n\end{landscape}\n"

    txt=""
    lines = data.to_string(header=True,index=False).split('\n')
    for i in range( 0, len( lines ) ):
        split = lines[i].split(" ")
        split = [ s.strip() for s in split if s.strip() != "" ]
        for j in range( 0, len( split ) ):
            txt += split[ j ]
            if j != len( split )-1:
                txt += "&"
        txt += "\\\\\n"
        if i == 0 :
            txt += "\\midrule "
    
    file = open( file_output, "w" )
    file.write( header + txt + footer )
