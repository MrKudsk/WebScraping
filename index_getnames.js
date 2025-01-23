const puppeteer = require('puppeteer');
const fs = require('fs/promises');

async function main() {
   const browser = await puppeteer.launch({
	executablePath: '/usr/bin/chromium-browser',});
   const page = await browser.newPage();
   await page.goto("https://learnwebcode.github.io/practice-requests/");
	// body > div > div > div > strong
   const names = await page.evaluate(() => {
       return Array.from(document.querySelectorAll(".info strong")).map(x => x.textContent)  
   });
   await fs.writeFile('names.txt', names.join("\r\n"));

   await browser.close();
}

console.log("Start");
main();
console.log("End");
