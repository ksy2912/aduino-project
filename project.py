import pyttsx3
import PyPDF2
pdf_book = open('book.pdf' , 'rb')
reading_pdf = PyPDF2.PdfFileReader(pdf_book)
pdf_pages = reading_pdf.numPages

pdf_speaker = pyttsx3.init()
choose_page = reading_pdf .getPage(0)
pdf_text=choose_page.extractText()
pdf_speaker.say(pdf_text)
pdf_speaker.runAndWait()
