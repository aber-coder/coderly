def main():
    s1 :str = input("Enter string: ")
    position :int = int(input("Enter position: "))
    while position >= len(s1):
        print("Invalid position")
        position = int(input("Enter position: "))
    
    ch :str = input("Enter character: ")
    s2 :str = "dlestx" + s1[:position] + "dle" + ch + s1[position:] + "dleetx"

    print(s2)
main()
